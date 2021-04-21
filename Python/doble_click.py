import os
import time

#os.startfile(r"C:\Users\HP\Desktop\apuntes_SO")
#print(archivo.st_atime)
#arr = os.stat(r"C:\Users\HP\Desktop\my.txt")
#print(arr.st_type)

import psutil
#for proc in psutil.process_iter(['pid', 'name']):
#    print(proc.info)

#for p in psutil.process_iter():
#    print(p, p.name(), p.pid)

#s = psutil.win_service_get(r"C:\Users\HP\Desktop\my.txt")
#s.as_dict()

"""
while 1:
    print("Espera 5 seg")
    time.sleep(5) # espera en segundos
"""

pid_id = 9524

# Informations of the Process with the PID ID
process_pid = psutil.Process(pid_id)
print(process_pid)
# Gives You PID ID, name and started date
# psutil.Process(pid=1216, name='ATKOSD2.exe', started='21:38:05')

# Name of the process
process_name = process_pid.name()
print(process_name)