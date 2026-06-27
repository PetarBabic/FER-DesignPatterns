def mymax(iterable, key = None):
    # incijaliziraj maksimalni element i maksimalni ključ
    max_x=max_key=None

    if(key == None):
        key = lambda x: x
    

    # obiđi sve elemente
    for x in iterable:
        current_key = key(x)

        if(max_x == None or current_key > max_key):
            max_x = x
            max_key = current_key

    # ako je key(x) najveći -> ažuriraj max_x i max_key

    # vrati rezultat
    return max_x

print("Najdulja:", mymax([
  "Gle", "malu", "vocku", "poslije", "kise",
  "Puna", "je", "kapi", "pa", "ih", "njise"], 
  lambda x: len(x)))

maxint = mymax([1, 3, 5, 7, 4, 6, 9, 2, 0])
maxchar = mymax("Suncana strana ulice")
maxstring = mymax([
  "Gle", "malu", "vocku", "poslije", "kise",
  "Puna", "je", "kapi", "pa", "ih", "njise"])

print("Maxint:", maxint)
print("Maxchar", maxchar)
print("Maxstring", maxstring)

D={'burek':8, 'buhtla':5}

print("Najskuplji proizvod:", mymax(D, lambda x: D[x]))

ljudi = [("Ana", "Kovač"), ("Marko", "Horvat"), ("Ivan", "Marić")]
for ljud in ljudi:
    print(ljud[1])
print("Posljednja osoba:", mymax(ljudi, lambda x: x[0]+x[1]))
