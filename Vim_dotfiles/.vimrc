" Enable number lines
set number 
" Follow indentation of the line above
set autoindent 
" Enable mouse support
set mouse=a
" add monokai colorscheme to vim
syntax enable
colorscheme monokai
" Set status bar
set laststatus=2
" Encoding
set encoding=UTF-8


" Call ~/.vim.plug file
if filereadable(expand("~/.vimrc.plug"))
	source ~/.vimrc.plug
endif

