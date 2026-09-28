import random, subprocess

def run(exe, inp):
    return subprocess.run([exe],input = inp, capture_output=True,text = True).stdout.strip()

for it in range(10):
    N = random.randint(5,10)
    Q = random.randint(5,20)
    inp = f"{N} {Q} \n"
    for i in range(Q):
        task = random.randint(1,2)
        X = random.randint(0,N)
        inp += f"{task} {X}"
        
    a,b = run("./solution",inp), run("./brute",inp)
    if a!=b:
        print("pair that failed,",inp, "our sol", a , "ans is" , b)
        break

else:
    print("PASS")