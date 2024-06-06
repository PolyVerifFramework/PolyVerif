#!/bin/bash

cmd="cd adehome &&  ./Poly_Suite/support_files/engage.sh"

gnome-terminal --tab --title="Enabling self-driving" -- bash -c "ade enter \"${cmd}\"; exit; $SHELL"