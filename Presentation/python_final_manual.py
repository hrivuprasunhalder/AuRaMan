import numpy as np
import matplotlib.pyplot as plt

# ------------------ MANUAL INPUT ------------------
data = """
3 4 2 2 1 2 5 4 3 4 0 0 6 4 1 18 6 6 
3 3 6 2 0 2 2 2 2 0 2 1 2 2 2 0 0 0
4 1 2 1 0 2 2 1 4 1 3 3 1 4 3 0 0 0
0 4 0 3 1 0 1 2 1 3 1 15 2 1 2 0 0 0
"""

# ------------------ PROCESS DATA ------------------
sweeps = []
lines = data.strip().split("\n")

for idx, line in enumerate(lines):
    row = [int(x) for x in line.strip().split()]
    
    if idx % 2 == 1:
        row.reverse()

    sweeps.append(row)

# Transpose so each sweep line is a vertical column
matrix = np.array(sweeps).T

# Flip horizontally so the first sweep (1 2 3) is on the far right
matrix = np.flip(matrix, axis=1)

# ------------------ PLOT RADIATION MAP ------------------
plt.figure(figsize=(7, 6))

img = plt.imshow(
    matrix,
    cmap='Reds',
    origin='lower',
    interpolation='bicubic', 
    aspect='auto'
)

plt.colorbar(img, label='Radiation Level')
plt.title("Smooth Radiation Heatmap", pad=15)
plt.xlabel("Horizontal Position")
plt.ylabel("Vertical Position")

plt.xticks([])
plt.yticks([])

plt.tight_layout()
plt.show()

