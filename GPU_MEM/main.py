# CURRENTLY THIS FILLS UP SYSTEM MEMORY AND NOT GPU_vRAM
# Apparently you can't allocate memory on the GPU directly and by defauly system memory gets allocated
# If anyone is able to figure out a way contributions are always welcome!

import pyopencl as cl # OpenCL - GPU computing interface
from pyopencl import device_info 
import numpy as np
import time
import sys

CONST_LOOP_AMOUNT = 200000000

# Hardware devices
platforms = cl.get_platforms()

# getting GPUs
my_gpu_devices = [platforms[0].get_devices(device_type=cl.device_type.GPU)[0]]
print(my_gpu_devices)

# Context set to GPU 0
ctx = cl.Context(devices = my_gpu_devices)

# Querying Local memory size
local_memory_size = my_gpu_devices[0].get_info(device_info.LOCAL_MEM_SIZE)

print("VRam size : ", local_memory_size)
# time.sleep(200)

flood_data = np.random.rand(256 ** 2).astype(np.int32)
print(sys.getsizeof(flood_data))

buf = cl.Buffer(ctx, 
                cl.mem_flags.READ_WRITE, 
                size = (local_memory_size - 1000), 
                hostbuf = None
)

queue = cl.CommandQueue(ctx)
localMem = cl.LocalMemory(sys.getsizeof(np.int32) * 128)

for _ in range (0, CONST_LOOP_AMOUNT):
    cl.enqueue_fill_buffer(
                queue = queue, 
                mem = buf, 
                pattern = np.int32(0), 
                offset = 0, 
                size =  int(sys.getsizeof(np.int32) * 128)
                
    )

# kernel = '''

# #define SIZE 9999   

# __kernel void allocateMe() {
        
#         __local uint A[SIZE];
#         __local uint B[SIZE];
#         __local uint C[SIZE];
#         __local uint D[SIZE];
#         __local uint E[SIZE];
#         __local uint F[SIZE];
#         __local uint G[SIZE];

# }

# '''

# for _ in range(0,1000000):
#     prg = cl.Program(ctx, kernel).build()
time.sleep(20)

# for _ in range(0, 10000000):
#     localMem = cl.LocalMemory(sys.getsizeof(np.int32) * 128 * 2)
#     # cl.enqueue_migrate_mem_objects(queue, buf,0, None)
#     # mem_alloc = cl.tools.ImmediateAllocator(queue, cl.mem_flags.READ_WRITE)


# 
