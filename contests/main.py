def vigenere_encrypt(p, k):
    c = ""
    k_len = len(k)
    for i, ch in enumerate(p):
        if ch.isalpha():
            k_ch = k[i % k_len].upper()
            if ch.isupper():
                shift = ord(k_ch) - ord('A')
                c += chr((ord(ch) - ord('A') + shift) % 26 + ord('A'))
            else:
                shift = ord(k_ch.lower()) - ord('a')
                c += chr((ord(ch) - ord('a') + shift) % 26 + ord('a'))
        else:
            c += ch
    return c

def vigenere_decrypt(c, k):
    p = ""
    k_len = len(k)
    for i, ch in enumerate(c):
        if ch.isalpha():
            k_ch = k[i % k_len].upper()
            if ch.isupper():
                shift = ord(k_ch) - ord('A')
                p += chr((ord(ch) - ord('A') - shift) % 26 + ord('A'))
            else:
                shift = ord(k_ch.lower()) - ord('a')
                p += chr((ord(ch) - ord('a') - shift) % 26 + ord('a'))
        else:
            p += ch
    return p

try:
    with open("input.txt", "r") as f_in:
        lines = f_in.readlines()
        if len(lines) < 2:
            raise ValueError("Input file must contain at least two lines: one for plaintext and one for key.")
        p = lines[0].strip() 
        k = lines[1].strip()        

except FileNotFoundError:
    print("Error: The file 'input.txt' was not found.")
    exit(1)
except ValueError as ve:
    print(f"Error: {ve}")
    exit(1)

print("Original Plaintext:", p)
print("Key:", k)

c = vigenere_encrypt(p, k)
print("Ciphertext:", c)

with open("output.txt", "w") as f_out:
    f_out.write(c)
with open("output.txt", "r") as f_out:
    c_read = f_out.read().strip()

p_decrypt = vigenere_decrypt(c_read, k)
print("Decrypted Text:", p_decrypt)
