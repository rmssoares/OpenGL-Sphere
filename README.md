# OpenGL: Bouncing Sphere
The *OpenGL-Sphere* was one of the assessments for the course of *Computer Graphics*, in the *University of Algarve*. The implementation was done, as the name indicates, in *OpenGL*.
Besides the creation of the sphere through a collection of recursively drawn triangles, there are several functionalities presented as the program runs, such as increasing the height of the sphere's jumps, the complexity, and the direction of the jumps.

## Getting Started

To start, clone the present repository into your local machine. If you're unaware of how to achieve this, please become familiar with the mechanisms of [GitHub](https://help.github.com/articles/set-up-git) repositories.

```
git clone git@github.com:thyriki/OpenGL-Sphere.git
```

### Prerequisites

Ensure that you have [OpenGL](http://www.prinmath.com/csci5229/misc/install.html) installed and properly set up. The link takes to a page with proper instructions.

### Instructions

Start by opening a terminal, and navigate to the project's folder, where the **sphere.c** file is.
Compile the file through the following command:

```
gcc -Wall -o sphere sphere.c -lglut32cu -lglu32 -lopengl32
```

After successfully compiling (if it doesn't, please review the setup of *OpenGL*, and ensure the *environment variable* was added), an *executable* will be created, and the *sphere* can be ran from the terminal through:

```
sphere
```

## Authors

* **Ricardo Soares** - [thyriki](https://github.com/thyriki)

For any inquiries, feel free to open up an issue.