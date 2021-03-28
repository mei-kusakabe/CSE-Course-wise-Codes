import math
from fuzzywuzzy import process
def sortSecond(val):
    return val[1]
def main():
            key = input("Enter key: ")
            x = 1
            encrptedmessages=[]
            while x <= 5:

                #key = "4312567"
                #message = "attackpostponeduntiltwoamxyz"
                message = input("Enter a message: ")
                #message = "attackpostponeduntiltwoamxyz"
                #s1 = "attackpostponeduntiltwoamxyz"
                if x==1:
                  cipher = encryptmessage(message, key)
                  encrptedmessages.append(cipher)
                  txt = cipher
                else:
                    cipher = encryptmessage(txt, key)
                    encrptedmessages.append(cipher)
                    txt = cipher

                #encrptedmessages.append(cipher)
                print("Encrypted message: ", cipher)
                x=x+1

            print("END OF INPUT.")
            print("All Encrypted message for given string: ", encrptedmessages)
            matchstr = "attackpostponeduntiltwoamxyz"
            Ratios = process.extract(matchstr, encrptedmessages)
            print("Encrypted text with Ratios: ",Ratios)
            Ratios.sort(key=sortSecond)
            print("Least Match for attackpostponeduntiltwoamxyz", end =" ")
            print(": ",end =" "),
            print(Ratios[0])

def encryptmessage(msg, key):
    msglen= len(msg)
    msglist = list(msg)
    cols = len(key)
    rows = int(math.ceil(msglen / cols))

    empty = int((rows * cols) - msglen)
    msglist.extend('x' * empty)

    cipher = [''] * cols

    for col in range(cols):
        i = col
        while i < len(msglist):
            cipher[col] += msglist[i]
            i += cols

    #print(cipher)

    keyPointer = 0
    keyList = sorted(list(key))
    cipherText = ""

    for i in range(cols):
        current = key.index(keyList[keyPointer])
        cipherText += ''.join(cipher[current])
        keyPointer += 1

    return cipherText


main()