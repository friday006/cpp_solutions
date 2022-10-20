import math

# Hectoberfest2022


def encryption(message):
    encrypt = ""
    print("Enter a Key Matrix of Key Matrix")
    r1 = int(input("Enter a Row"))
    c1 = int(input("Enter a Column"))
    arr1 = [[int(input("Enter a value")) for i in range(c1)]for j in range(r1)]
    l = len(message)
    c2 = r1
    r2 = math.ceil(l/c2)
    k = 0
    arr2 = []
    for i in range(r2):
        row = []
        for j in range(c2):
            if(k > l-1):
                row.append(ord('Z')-65)
            else:
                row.append(ord(message[k])-65)
                k = k+1
        arr2.append(row)
    ans = [[0 for i in range(0, c1)]for j in range(0, r2)]
    for i in range(0, r2):
        for j in range(0, c1):
            for k in range(0, r1):
                ans[i][j] += (arr2[i][k]*arr1[k][j])
    for i in range(r2):
        for j in range(c1):
            ans[i][j] = (ans[i][j] % 26)
            k = ans[i][j]+65
            encrypt += (chr(k))
    return encrypt


def decryption(ciphertext):
    decrypt = ""
    print("Enter a Inverse Matrix of Key Matrix")
    r1 = int(input("Enter a Row"))
    c1 = int(input("Enter a Column"))
    arr1 = [[int(input("Enter a value")) for i in range(c1)]for j in range(r1)]
    l = len(ciphertext)
    c2 = r1
    r2 = math.ceil(l/c2)
    k = 0
    arr2 = []
    for i in range(r2):
        row = []
        for j in range(c2):
            if(k > l-1):
                row.append(ord('Z')-65)
            else:
                row.append(ord(ciphertext[k])-65)
                k = k+1
        arr2.append(row)
    ans = [[0 for i in range(0, c1)]for j in range(0, r2)]
    for i in range(0, r2):
        for j in range(0, c1):
            for k in range(0, r1):
                ans[i][j] += (arr2[i][k]*arr1[k][j])
    for i in range(r2):
        for j in range(c1):
            ans[i][j] = (ans[i][j] % 26)
            k = ans[i][j]+65
            decrypt += (chr(k))
    return decrypt


print("IN this code you give matrix with inverse matrix value\n ")
message = input("Enter a Message\n : ")
# for encryptioin
print("MESSAGE IS : ", message)
ciphertext = encryption(message)
print("\nENCRYPT MESSAGE : \n", ciphertext)
print("\nDECRYPT MESSAGE :\n", decryption(ciphertext))
