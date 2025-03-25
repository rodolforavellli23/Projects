# User made aliases

alias lsactive='systemctl --user list-units --type service'
alias pipx='function _pipx(){
    if [ $1 = "search" ]; then
        pip_search "$2";
    else pipx "$@";
    fi;
};_pipx' # If you install pip on a new machine, be sure to also install 'pip_search' & 'pipx'

