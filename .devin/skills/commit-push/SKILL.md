# Commit and Push Changes

---
## Permissions
- exec: true
- read: true
- edit: true
---

Este skill automatiza el proceso de hacer commit y push de todos los cambios del repositorio con un mensaje descriptivo.

## Pasos a seguir:

1. **Verificar cambios pendientes:**
   - Ejecuta `git status` para ver qué archivos han sido modificados, agregados o eliminados.

2. **Agregar todos los cambios:**
   - Ejecuta `git add .` para agregar todos los cambios al staging area.

3. **Generar mensaje de commit descriptivo:**
   - Analiza los cambios usando `git diff --cached` para entender qué se modificó.
   - Crea un mensaje de commit que:
     - Sea conciso pero descriptivo (máximo 50 caracteres en la primera línea)
     - Use el tiempo presente (ej: "agregar" no "agregó")
     - Describa el tipo de cambio (feat, fix, docs, style, refactor, test, chore)
     - Incluya detalles relevantes en el cuerpo del mensaje si es necesario

   Formato sugerido:
   ```
   <tipo>: <descripción breve>

   <detalles adicionales si es necesario>
   ```

4. **Hacer commit:**
   - Ejecuta `git commit -m "<mensaje descriptivo>"` con el mensaje generado.
   - Para PowerShell, usa múltiples parámetros `-m` si necesitas incluir detalles adicionales:
     ```
     git commit -m "tipo: descripción breve" -m "- detalle adicional 1" -m "- detalle adicional 2"
     ```

5. **Hacer push:**
   - Ejecuta `git push` para enviar los cambios al repositorio remoto.

## Configuración de permisos:
Este skill requiere las siguientes herramientas sin autorización humana:
- `exec`: Para ejecutar comandos git (git status, git add, git commit, git push)
- `read`: Para leer el archivo de skill si es necesario
- `edit`: Para actualizar este archivo de skill

**Nota:** Los comandos git están configurados para auto-aprobación en `.devin/config.json` a nivel de proyecto.

## Ejemplo de uso:
- Invocar este skill cuando hayas terminado de trabajar en una tarea y quieras guardar y compartir tus cambios.
- El skill analizará automáticamente los cambios y creará un mensaje apropiado.
