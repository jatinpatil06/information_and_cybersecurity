def apply_function(block, keys, i):
    return (block ^ keys[i]) 

#Accepting the plaintext
plaintext_block = input("Enter the plaintext : ")
le = []
re = []
le.append(int(plaintext_block[:8]))
re.append(int(plaintext_block[8:]))

#Accepting the keys
keys = []
print("Enter the keys ->")
for i in range(2):
    keys.append(int(input(f"Key {i+1} = ")))

#Encrypting the blocks
for i in range(2):
    le.append(re[i])
    re.append(apply_function(re[i], keys, i) ^ le[i])
    print(f"le{i} = {str(le[i]).zfill(8)} re{i} = {str(re[i]).zfill(8)}")

print(f"Encrypted value : {str(le[2]).zfill(8)} {str(re[2]).zfill(8)}")
