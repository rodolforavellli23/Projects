" Enable number lines
set number 
" Follow indentation of the line above
set autoindent 
" Enable mouse support
set mouse=a
" Set editor color theme 
colorscheme molokai 
" Set status bar
set laststatus=2
" Call ~/.vim.plug file
if filereadable(expand("~/.vimrc.plug"))
	source ~/.vimrc.plug
endif

