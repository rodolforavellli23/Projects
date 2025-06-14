# User made aliases

alias lsd="lsd --group-directories-first"
alias lsactive='systemctl --user list-units --type service'
alias pipx='function _pipx(){
    if [ $1 = "search" ]; then
        pip_search "$2";
    else pipx "$@";
    fi;
};_pipx' # If you install pip on a new machine, be sure to also install 'pip_search' & 'pipx'
alias prepend='function _prepend(){
     { echo "$1"; cat "$2"; } | tee "$2" > /dev/null
};_prepend' # This adds a new first line to a text file
alias gimp3='flatpak run org.gimp.GIMP'

