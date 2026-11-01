@echo off
:: Aquí escribes la ruta que tú quieras entre comillas:
set "DIR_ACTUAL=C:\Users\GIANPIER\Desktop\Terminal"

where wt >nul 2>nul
if %errorlevel% equ 0 (
    wt -d "%DIR_ACTUAL%" --title "Saludos" cmd /k python saludos.py ; new-tab -d "%DIR_ACTUAL%" --title "Operaciones" cmd /k python operaciones.py ; new-tab -d "%DIR_ACTUAL%" --title "Mensajes" cmd /k python mensajes.py
) else (
    start "Saludos" /D "%DIR_ACTUAL%" cmd /k python saludos.py
    start "Operaciones" /D "%DIR_ACTUAL%" cmd /k python operaciones.py
    start "Mensajes" /D "%DIR_ACTUAL%" cmd /k python mensajes.py
)