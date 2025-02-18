import os
import random
import string
import shutil
import time

# Funzione per generare una stringa casuale
def random_string(length=10):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

# Funzione per creare una struttura di directory casuale
def create_random_directory_tree(base_path, depth=3, breadth=3):
    if depth == 0:
        return
    
    for _ in range(random.randint(1, breadth)):
        dir_name = random_string()
        dir_path = os.path.join(base_path, dir_name)
        os.makedirs(dir_path, exist_ok=True)
        create_random_directory_tree(dir_path, depth - 1, breadth)

# Funzione per creare un file casuale di dimensioni variabili
def create_random_file(file_path):
    file_size = random.randint(100, 10000)  # File size tra 100 bytes e 10KB
    with open(file_path, 'wb') as f:
        f.write(os.urandom(file_size))

# Funzione per creare link simbolici (sia funzionanti che rotti)
def create_symbolic_links(base_path, num_links=2):
    # Otteniamo la lista di file e sottocartelle presenti nella directory
    files_and_dirs = os.listdir(base_path)
    
    # Assicuriamoci che ci siano file o cartelle da cui creare i link simbolici
    if files_and_dirs:
        for _ in range(num_links):
            target_path = random.choice(files_and_dirs)  # Scegliamo un file o una cartella
            link_name = random_string() + '.link'
            link_path = os.path.join(base_path, link_name)
            
            # Crea un link simbolico funzionante
            os.symlink(target_path, link_path)
    
    # Creiamo un link simbolico rotto (che punta a un file inesistente)
    broken_link = random_string() + '.broken_link'
    broken_link_path = os.path.join(base_path, broken_link)
    os.symlink('non_existent_file', broken_link_path)


# Funzione per impostare permessi casuali sui file e directory
def set_random_permissions(path):
    permissions = random.choice([0o777, 0o755, 0o700, 0o644, 0o600])
    os.chmod(path, permissions)

# Funzione principale per generare la struttura completa
def generate_directory_structure(base_path, depth=3, breadth=3):
    # Crea la directory principale
    os.makedirs(base_path, exist_ok=True)

    # Crea la struttura di directory
    create_random_directory_tree(base_path, depth, breadth)

    # Popola le directory con file casuali
    for root, dirs, files in os.walk(base_path):
        if random.random() < 0.7:  # Circa il 70% delle directory sarà popolato con file
            for _ in range(random.randint(1, 5)):  # Crea 1-5 file per directory
                file_name = random_string() + '.txt'
                file_path = os.path.join(root, file_name)
                create_random_file(file_path)
                set_random_permissions(file_path)

        # Aggiungi link simbolici funzionanti e rotti
        if random.random() < 0.5:  # Circa il 50% delle directory avrà link simbolici
            create_symbolic_links(root)

        # Imposta permessi casuali su directory
        set_random_permissions(root)

if __name__ == "__main__":
    base_path = "files"
    generate_directory_structure(base_path)
    print(f"Struttura delle directory creata in: {base_path}")
