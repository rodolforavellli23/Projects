import re

string = "Meu Endereço:\n\nEstrada União e Indústria, nº 9153, Itaipava, Petrópolis-RJ, Brasil, CEP: 25730-736"

match = re.search(r"\b\w+ia\b", string)

if match:
  print(match.group(0)) 
else:
  print("Palavra não encontrada")
