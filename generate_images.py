import matplotlib.pyplot as plt
import numpy as np

# Leer archivos CSV
def leer_csv(nombre_archivo):
    data = np.loadtxt(nombre_archivo, delimiter=',')
    x = data[:, 0]
    u = data[:, 1]
    return x, u

# Leer datos
x_init, u_init = leer_csv('initialCondition.csv')
x_final, u_final = leer_csv('final.csv')

# Graficar
plt.figure(figsize=(8, 5))
plt.plot(x_init, u_init, label='Condición inicial', linestyle='--')
plt.plot(x_final, u_final, label='Solución final', linestyle='-')
plt.xlabel('x')
plt.ylabel('u(x)')
plt.title('Evolución de la onda')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('evolucion_onda.png')
plt.show()
