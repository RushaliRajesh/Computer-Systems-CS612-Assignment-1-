import time

rows, cols = (1024, 1024)

a = [[1 for i in range(cols)] for j in range(rows)]
b = [[1 for i in range(cols)] for j in range(rows)]
c = [[0 for i in range(cols)] for j in range(rows)]

start = time.process_time()
for i in range(rows):
  for j in range(cols):
    for k in range(cols):
      c[i][j] = c[i][j]+a[i][k]*b[j][k]

end = time.process_time()
print((end-start), "secs - time")