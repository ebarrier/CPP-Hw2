# Conway's Game of Life  
The programme is a school **C++** project for the 'Basics of C/C++' course, semester 3.  
It uses [**SFML**](http://www.sfml-dev.org/) (Simple and Fast Multimedia Library).  

##Author  
Author of  project is **Etienne Barrier**.  
Author can be contacted at *ebarrier@itcollege.ee*.  

## License  
MIT license: [LICENSE file in repo](https://github.com/ebarrier/CPP-Hw2/blob/master/LICENSE).  

## Description  of the game
[From Wikipedia](https://en.wikipedia.org/wiki/Conway's_Game_of_Life):  
> The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.  
> The "game" is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.  
> One interacts with the Game of Life by creating an initial configuration and observing how it evolves, or, for advanced "players", by creating patterns with particular properties.  

## How does it work?
The first window will display a grid which cells can be turned alive/dead by clicking on them.  
`Space` bar toggles the animation of cells to run or to pause.  
While animation is paused, one can click on cells to swith their life state.  
While animation is running, it is not possible to click on cells to switch their life state.  
At any moment the `R` key resets the game to the original state.