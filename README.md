# cub3D

Cub3D is a 42 school team project to create a dynamic view inside a 3D maze. Using the [MiniLibX library](https://github.com/codam-coding-college/MLX42), we must implement raycasting in the style of the famous [Wolfenstein 3D](http://users.atw.hu/wolf3d/) game, the first-person shooter (FPS) in videogame history.

## Status

Grade: 115%.

## Clone

Clone the repository including the MiniLibX submodule:

```shell
git clone https://github.com/ysahih/cub3D.git
```

## Compile and Run

To compile the game, `cd` into the cloned directory and:
  
  - Compile the project using the provided build instructions:
  ```shell
  make
  ```

  - Run the executable to launch Cub3D:
  ```shell
  ./cub3D <path/to/map.cub>
  ```

  - Enjoy exploring the graphical features and mathematical applications within the project.


The program takes a map file as an argument. Maps are available in the `maps` directory.

For example:
- `./cub3D maps/map.cub` should run.


## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `left arrow`: rotate left
- `right arrow`: rotate right
- `mouse`: rotate by moving the mouse

## Useful Resources

Useful resources for this project are:

- MLX42: [codam MLX42 documentation](https://github.com/codam-coding-college/MLX42/wiki)
- Raycasting: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)
- Raycasting: [Permadi's Raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- Movement: [Calculating heading in 2d games: Using trigonometric functions part 1](http://gamecodeschool.com/essentials/calculating-heading-in-2d-games-using-trigonometric-functions-part-1/)

---
Made by sahih and isBarka



