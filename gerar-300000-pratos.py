import random
import string
import csv

def generate_fixed_names(num_names):
    names = set()
    while len(names) < num_names:
        length = random.randint(5, 20)
        name = ''.join(random.choices(string.ascii_lowercase + '-', k=length))
        if all(c in string.ascii_lowercase + '-' for c in name):  # Verifique se todos os caracteres são válidos
            names.add(name)
    return list(names)

def generate_dishes(num_dishes, names):
    dishes = []
    for _ in range(num_dishes):
        priority = random.randint(1, 300000)
        time = random.randint(1, 999)
        name = random.choice(names)
        # Verifica se os números são válidos
        if isinstance(priority, int) and isinstance(time, int):
            dishes.append((priority, time, name))
    return dishes

# Define o número de nomes fixos que você deseja reutilizar
num_names = 10
fixed_names = generate_fixed_names(num_names)

# Gera 300.000 pratos utilizando o conjunto fixo de nomes
dishes = generate_dishes(300000, fixed_names)

# Salva em um arquivo CSV
with open('dishes.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Priority', 'Time', 'Name'])
    for dish in dishes:
        writer.writerow([dish[0], dish[1], dish[2]])

print("Arquivo dishes.csv gerado com sucesso!")