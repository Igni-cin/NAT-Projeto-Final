# Projeto-Final
Este projeto tem como objetivo instruir a instalação e utilização da ferramenta Open Source [Mull](https://github.com/mull-project/mull?tab=readme-ov-file), **Mull** é uma ferramenta baseada em LLVM/Clang capaz de injetar e achar mutações em programas baseados em C/C++.

# Requisitos para funcionamento
- LLVM (versão compatível com Mull)
- Clang
- **Obs.: para o funcionamento perfeito desse tutorial é essencial a utilização do SOP Ubuntu 24.04.2 LTS e as versões clang-18(18.1.3), mesmo que as intruções do repositório sejam bem claras quanto a compatibilidade das versões 20.04/22.04 do Ubuntu e llvm/Clang do 12 ao 18, acontecem muitos problemas pra compatibilizar com o repositório atual.**

# Instalação
configura o repositório apt para inserir o **Mull**:

```bash
"curl -1sLf 'https://dl.cloudsmith.io/public/mull-project/mull-stable/setup.deb.sh' | sudo -E bash"

Instalar a versão recente do Mull:

```bash
$ sudo apt-get update
$ sudo apt-get install mull-18

Verificar se instalação e versão:

```bash
$ mull-runner-18 --version
Mull: Practical mutation testing for C and C++
Home: https://github.com/mull-project/mull
Docs: https://mull.readthedocs.io
Support: https://mull.readthedocs.io/en/latest/Support.html
Version: 0.25.0
Commit: 319e8b0
Date: 01 Mar 2025
LLVM: 18.1.3


