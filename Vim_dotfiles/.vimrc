" Enable number lines
set number 

" Follow indentation of the line above
set autoindent 

" Enable mouse support
set mouse=a

syntax enable

colorscheme retrobox

" Set status bar
set laststatus=2

" Encoding
set encoding=UTF-8

filetype plugin indent on

" Call ~/.vim.plug file
if filereadable(expand("~/.vimrc.plug"))
	source ~/.vimrc.plug
endif

