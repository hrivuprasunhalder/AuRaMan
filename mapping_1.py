import serial
import numpy as np
import matplotlib.pyplot as plt


ser = serial.Serial('COM7', 9600, timeout=2)


def read_n_rows(n=20):
    rows = []
    while len(rows) < n:
        line = ser.readline().decode('ascii', errors='ignore').strip()
        if not line:
            continue
        try:
            numbers = [int(x) for x in line.split()]
        except ValueError:
            continue
        rows.append(numbers)
    return rows


rows = read_n_rows(20)
target_len = len(rows[0])
processed_rows = []


for row in rows:
    r = row.copy()

    if len(r) > target_len:
        num_to_remove = len(r) - target_len
        smallest_indices = sorted(range(len(r)), key=lambda i: (r[i], i))[:num_to_remove]
        smallest_set = set(smallest_indices)
        r = [v for i, v in enumerate(r) if i not in smallest_set]

    elif len(r) < target_len:
        num_to_add = target_len - len(r)
        sorted_r = sorted(r)
        if not sorted_r:
            avg_low = 0  
        else:
            k = min(2, len(sorted_r))               
            avg_low = round(sum(sorted_r[:k]) / k)  
        r.extend([avg_low] * num_to_add)

    processed_rows.append(r)
matrix = np.array(processed_rows, dtype=int)
print(matrix)
plt.figure(figsize=(8,6))
plt.imshow(matrix,cmap='inferno',interpolation='nearest')
plt.colorbar(label='Radiation Level')
plt.title("Radiation Map")
plt.show()
input("Press Enter to exit...")
