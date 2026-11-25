import os
import urllib.request
import cv2
import mediapipe as mp
from mediapipe.tasks import python
from mediapipe.tasks.python import vision

# --- DESCARGA AUTOMÁTICA DEL MODELO ---
MODEL_PATH = 'hand_landmarker.task'
MODEL_URL = 'https://storage.googleapis.com/mediapipe-models/hand_landmarker/hand_landmarker/float16/1/hand_landmarker.task'

if not os.path.exists(MODEL_PATH):
    print("Modelo no encontrado. Descargando 'hand_landmarker.task'...")
    urllib.request.urlretrieve(MODEL_URL, MODEL_PATH)
    print("Descarga completada.")
# --------------------------------------

# Conexiones entre los 21 puntos de la mano para dibujarlos con OpenCV
HAND_CONNECTIONS = [
    (0, 1), (1, 2), (2, 3), (3, 4),        # Pulgar
    (0, 5), (5, 6), (6, 7), (7, 8),        # Índice
    (5, 9), (9, 10), (10, 11), (11, 12),   # Medio
    (9, 13), (13, 14), (14, 15), (15, 16), # Anular
    (13, 17), (0, 17), (17, 18), (18, 19), (19, 20) # Meñique y palma
]

# Configurar el detector usando el archivo .task
base_options = python.BaseOptions(model_asset_path=MODEL_PATH)
options = vision.HandLandmarkerOptions(
    base_options=base_options,
    running_mode=vision.RunningMode.VIDEO,
    num_hands=2,
    min_hand_detection_confidence=0.5,
    min_tracking_confidence=0.5
)

detector = vision.HandLandmarker.create_from_options(options)
cap = cv2.VideoCapture(0)
frame_timestamp_ms = 0

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print("No se pudo acceder a la cámara.")
        break

    frame = cv2.flip(frame, 1)
    h, w, _ = frame.shape

    # Convertir de BGR (OpenCV) a RGB y crear un objeto mp.Image
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_frame)

    # El modo VIDEO requiere una marca de tiempo creciente en milisegundos
    frame_timestamp_ms += 33
    result = detector.detect_for_video(mp_image, frame_timestamp_ms)

    # Dibujar puntos y líneas si hay manos detectadas
    if result.hand_landmarks:
        for landmarks in result.hand_landmarks:
            # Convertir coordenadas normalizadas (0 a 1) a píxeles
            points = [(int(lm.x * w), int(lm.y * h)) for lm in landmarks]

            # Dibujar conexiones
            for start_idx, end_idx in HAND_CONNECTIONS:
                cv2.line(frame, points[start_idx], points[end_idx], (0, 255, 0), 2)

            # Dibujar articulaciones
            for x, y in points:
                cv2.circle(frame, (x, y), 4, (0, 0, 255), -1)

    cv2.imshow('Deteccion de Manos - MediaPipe Tasks', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

detector.close()
cap.release()
cv2.destroyAllWindows()