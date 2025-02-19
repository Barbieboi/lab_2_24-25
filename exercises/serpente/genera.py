import os
import random
import string

def generate_random_text(size=1024):
    """Genera una stringa casuale della dimensione specificata."""
    return ''.join(random.choices(string.ascii_letters + string.digits, k=size))

def create_random_files_and_dirs(base_path, depth, max_depth, max_files=3, max_dirs=2, broken_links=2, alias_prob=0.2, inaccessible_prob=0.2):
    """Genera un numero casuale di file e directory in base_path fino a max_depth."""
    if depth > max_depth:
        return
    
    num_files = random.randint(1, max_files)
    num_dirs = random.randint(1, max_dirs)
    explored_dirs = set()
    
    extensions = [".txt", ".c", ".h"]
    
    for _ in range(num_files):
        ext = random.choice(extensions)  # Seleziona casualmente un'estensione
        file_name = ''.join(random.choices(string.ascii_lowercase, k=8)) + ext
        file_path = os.path.join(base_path, file_name)
        file_size = random.randint(512, 4096)  # File tra 512B e 4KB
        with open(file_path, 'w') as f:
            f.write(generate_random_text(file_size))
        
        # Possibilità di rendere un file inaccessibile
        if random.random() < inaccessible_prob:
            os.chmod(file_path, 0o000)  # Nessun permesso di accesso

    for _ in range(num_dirs):
        dir_name = ''.join(random.choices(string.ascii_lowercase, k=8))
        dir_path = os.path.join(base_path, dir_name)
        os.makedirs(dir_path, exist_ok=True)
        explored_dirs.add(dir_path)
        create_random_files_and_dirs(dir_path, depth + 1, max_depth, max_files, max_dirs, broken_links, alias_prob, inaccessible_prob)

        # Possibilità di creare alias ricorsivi
        if random.random() < alias_prob and explored_dirs:
            alias_name = ''.join(random.choices(string.ascii_lowercase, k=8))
            alias_path = os.path.join(base_path, alias_name)
            target = random.choice(list(explored_dirs))
            os.symlink(target, alias_path)

    # Creazione di broken link
    for _ in range(broken_links):
        broken_name = ''.join(random.choices(string.ascii_lowercase, k=8))
        broken_path = os.path.join(base_path, broken_name)
        os.symlink("/nonexistent/path" + broken_name, broken_path)

if __name__ == "__main__":
    base_directory = "random_fs01"
    max_depth = 2  # Modifica per cambiare la profondità massima
    os.makedirs(base_directory, exist_ok=True)
    create_random_files_and_dirs(base_directory, 0, max_depth)