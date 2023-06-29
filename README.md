# Program Purpose #

This program generates an array of stats for use in TTRPGs (Tabletop Role Playing Games).
The intention of this stat generation method is to create a matrix of numbers where each
row, column, and diagnal add up to the same number. From there each player can pick a row,
column or diagnal as their stat spread. To add more diversity to the player's stats, it is
recommended to only allow each row, column, or diagnal to be picked by one and only one player.
This also has the benefit of getting the players to talk and figure out how they are going
to divy up stats before the start of the campaign.

# Technical Details #

Each diagnal, row, and column add up to a specific number that is set by the user. The
program also asks for a maximum and minimum number for each stat. These numbers can not
exceed the absolute minimum and absolute maximum, which are 1 and 18 by default. The 
number of stats is set to 6 by default.

If you wants to change the absolute minimum or absolute maximum, then that can be changed
in the header file (statGen.h), under the ABS_MIN and ABS_MAX variables respectively.

If you want to generate a different number of stats. That can also be changed in the header
file under the SIZE variable.

The make command will compile and run the program as normal. If you want to see the sum of
each line, run make sum.

# May the rolls be forever in your favor. #
