#!/bin/bash
#
# name: cargo-show
# desc: get package information from crates.io using `cargo-show [packagename]`
#
debug_colors()
{
  for i in {0..256}; do
    echo -e "\e[38;5;${i}m ${i}  \e[0m"
  done
}
get_fg_color()
{
  [ -z $1 ] && color_num=0 || color_num=$1
  [ -z $2 ] && content=$1 || content=${@:2}
  echo -e "\e[38;5;${color_num}m ${content}  \e[0m"
}
get_bg_color()
{
  [ -z $1 ] && color_num=0 || color_num=$1
  [ -z $2 ] && content=$1 || content=${@:2}
  # content=$2
  echo -e "\e[48;5;${color_num}m ${content}  \e[0m"
}
get_fgbg_color()
{
  [ -z $1 ] && fg_color=0 || fg_color=$1
  [ -z $2 ] && bg_color=1 || bg_color=$2
  [ -z $3 ] && content="bg: ${fg_color} fg: ${bg_color}" || content=${@:3}
  echo -e "\e[48;5;${fg_color}m \e[38;5;${bg_color}m  ${content}  \e[0m"
}
base_url="https://crates.io/api/v1/crates/"
crate_name=$(curl -s "${base_url}/${1}" |
  cat |
  jq .crate.name |
  tr -d '"')
[ ${crate_name} = "null" ] && crate_homepage="[-]"
crate_description=$(curl -s "${base_url}/${1}" |
  cat |
  jq .crate.description |
  tr -d '"')
if [[ ${crate_description} == "null" ]]; then
  crate_description="[-]"
fi
crate_repository=$(curl -s "${base_url}/${1}" |
  cat |
  jq .crate.repository |
  tr -d '"')
if [[ ${crate_repository} == "null" ]]; then
  crate_repository="[-]"
fi
crate_homepage=$(curl -s "${base_url}/${1}" |
  cat |
  jq .crate.homepage |
  tr -d '"')
if [[ ${crate_homepage} == "null" ]]; then
  crate_homepage="[-]"
fi
crate_keywords=$(curl -s "${base_url}/${1}" |
  cat |
  jq .crate.keywords |
  grep -P '"(.*)"' |
  tr -d "\n" |
  tr -d " " |
  tr -d '"')
[ ${crate_keywords} = "null" ] && crate_keywords="[-]"
if [[ ${crate_keywords} == "null" ]]; then
  crate_keywords="[-]"
fi
get_fgbg_color 232 196 "Name: "
get_fgbg_color 0 216 ${crate_name}
get_fgbg_color 0 196 "Description: "
get_fgbg_color 0 216 ${crate_description}
get_fgbg_color 0 196 "Repository: "
get_fgbg_color 0 216 ${crate_repository}
get_fgbg_color 0 196 "Homepage: "
get_fgbg_color 0 216 ${crate_homepage}
get_fgbg_color 0 196 "Keywords: "
get_fgbg_color 0 216 ${crate_keywords}

