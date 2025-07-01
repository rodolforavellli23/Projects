# User made aliases

alias lsd="lsd --group-directories-first" # I just like to have my file directories shown first really

alias lsactive='systemctl --user list-units --type service' # Shows active Systemd units

alias pipx='function _pipx(){
    if [ $1 = "search" ]; then
        pip_search "$2";
    else pipx "$@";
    fi;
};_pipx' # If you install pip on a new machine, be sure to also install 'pip_search' & 'pipx'

alias prepend='function _prepend(){
     { echo "$1"; cat "$2"; } | tee "$2" > /dev/null
};_prepend' # This adds a new first line to a text file

alias gimp3='flatpak run org.gimp.GIMP' # invokes Gimp 3

alias find_locate_exclusive='function _find_locate_exclusive(){
     locate -i "$1" | grep -viE "$2"
};_find_locate_exclusive' # case insensitive search for $something while excluding $other_thing from the search results

alias weather="curl wttr.in?format=3" # a cool way to see the local weather on the cli
