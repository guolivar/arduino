
def yaourt (*packages)
    install("yaourt", packages, " -S ")
end

def pacman (*packages)
    install("pacman", packages)
end

def install (manager, packages, flag = " -Syu ")
    manager + flag + packages.join(" ") + " --noconfirm \n"
end

def install_haskell_ide()
    "curl -L https://git.io/haskell-vim-now > /tmp/haskell-vim-now.sh \n bash /tmp/haskell-vim-now.sh"
end

def provision()
     pacman("yaourt") + " " + yaourt("par", "stack") + " " + install_haskell_ide()
     #packages = pacman("ctags", "yaourt", "i3", "i3-wm") + yaourt("par", "stack") + install_haskell_ide()
end