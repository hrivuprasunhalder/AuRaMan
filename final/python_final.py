import serial
import numpy as np
import matplotlib.pyplot as plt

# ------------------ Serial Configuration ------------------
ser = serial.Serial('COM3', 9600, timeout=2)

TOTAL_ROWS = 5   # total sweeps to capture

# ------------------ Read Rows ------------------
rows = []

while len(rows) < TOTAL_ROWS:
    line = ser.readline().decode('ascii', errors='ignore').strip()
    if not line:
        continue

    try:
        row = [int(x) for x in line.split()]
    except ValueError:
        continue

    rows.append(row)

# ------------------ Normalize Row Length ------------------
# First row defines length
target_len = len(rows[0])
processed_rows = []

for idx, row in enumerate(rows):
    r = row.copy()

    # Trim if too long
    if len(r) > target_len:
        r = r[:target_len]

    # Pad if too short
    elif len(r) < target_len:
        avg = round(sum(r) / len(r)) if r else 0
        r.extend([avg] * (target_len - len(r)))

    # Zig-zag scan correction
    if idx % 2 == 1:      # 2nd, 4th, ...
        r.reverse()

    processed_rows.append(r)

matrix = np.array(processed_rows, dtype=int)

# ------------------ Debug Output ------------------
print("Matrix shape:", matrix.shape)
print(matrix)

# ------------------ Plot Radiation Map ------------------
plt.figure(figsize=(8, 6))

plt.imshow(
    matrix,
    cmap='RdBu_r',        # Blue (low) → Red (high)
    interpolation='bilinear',
    aspect='auto'
)

plt.colorbar(label='Radiation Level')
plt.title("Radiation Map")
plt.xlabel("Sweep Position")
plt.ylabel("Sweep Number")

plt.tight_layout()
plt.show()

input("Press Enter to exit...")