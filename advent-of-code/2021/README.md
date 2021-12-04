# aoc 2021

```sh
cat 1.txt | node ./1.js
```

or, if using the [`compiler` script](https://github.com/kiprasmel/voidrice/blob/master/.local/bin/compiler):

```sh
compiler 1.js
```

which can be used inside [e.g. vim](https://github.com/kiprasmel/voidrice/blob/57cc606dd32e952d73305decb70048af858ce310/.config/nvim/init.vim#L358-L359):

```viml
map <leader>c :w! \| !compiler <c-r>%<CR>
```

and then with the file open, pressing `<leader>c` will run the file (with the txt file provided as stdin).

