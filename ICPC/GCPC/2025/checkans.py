import random, subprocess

def run(exe, inp):
    return subprocess.run([exe],input = inp, capture_output=True,text = True).stdout.strip()

for it in range(1000):
    inp = f"{random.randint(2,5)} {random.randint(1,5)} \n"
    a,b = run("./solution",inp), run("./brute",inp)
    if a!=b:
        print("pair that failed,",inp, "our sol", a , "ans is" , b)
        break

else:
    print("perfect")