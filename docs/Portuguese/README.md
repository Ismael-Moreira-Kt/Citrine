# Citrine
Citrine é uma biblioteca em C que fornece uma interface para operações de arquivos e diretórios, incluindo criação, leitura, escrita, remoção, e manipulação de permissões e propriedades de arquivos e diretórios. A biblioteca utiliza chamadas de sistema diretamente para realizar essas operações, proporcionando uma maneira eficiente e direta de manipular arquivos e diretórios no sistema.

<br><br>

## Instalação
Para compilar e instalar o Citrine, você precisa ter o CMake e o NASM instalados no seu sistema. Siga os passos abaixo:
- Clone o repositório:
```bash
git clone https://github.com/Ismael-Moreira-Kt/Citrine
```

- Se quiser ter uma prévia do que a biblioteca pode fazer:
```bash
    cd Citrine
    mkdir build
    cd build
    cmake ..
    make
```

<br><br>

## Uso
Para utilizar a biblioteca Citrine em seu projeto, inclua o cabeçalho `citrine.h` e link com a biblioteca ao compilar. Se quiser ter acesso a exemplos de uso e informação acerca dos métodos, visite a [documentação](./C/README.md) e os [exemplos de uso](../../examples/).

<br><br>

## Licença
Este projeto é licenciado sob a Licença MIT. Veja o arquivo [LICENSE](../../LICENSE) para mais detalhes.