#!/bin/sh
## export_lib.sh for export_lib in /home/roledg/cpp_bomberman
## 
## Made by role-d_g
## Login   <roledg@epitech.net>
## 
## Started on  Thu May 15 18:35:57 2014 role-d_g
## Last update Thu May 15 21:56:19 2014 role-d_g
##

run_command()
{
    LD_LIBRARY_PATH=./LibBomberman_linux_x64/libs
    export	LD_LIBRARY_PATH
    echo	"-- -- [Compilation] -- --\n"
    make re
    echo	"\n-- -- [See the available commands in the options] -- --\n"
    exec	bash
}

usage()
{
    echo	"\n-- -- [Export Bomberman library] -- --"
    echo	"-- -- [New bash was opened] -- --\n"
    run_command
}

usage $#