# User made aliases

alias gh='history|grep'
alias archi='lscpu | grep Arquitetura'
alias lsactive='systemctl --user list-units --type service'
alias cargoup='cargo install $(cargo install --list | egrep "^[a-z0-9_-]+ v[0-9.]+:$" | cut -f1 -d " ")'
alias pipx='function _pipx(){
    if [ $1 = "search" ]; then
        pip_search "$2";
    else pipx "$@";
    fi;
};_pipx' # If you install pip on a new machine, be sure to also install 'pip_search' & 'pipx'

