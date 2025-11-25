# CS230 Infer Demo
This project is a demonstration of the [Infer](https://fbinfer.com) tool for the UCLA Fall 2025 CS230 section. Infer is a static analysis tool for C,C++, and Java projects developed by Facebook.

## Getting Started
Infer provides [setup instructions](https://fbinfer.com/docs/getting-started) to begin using the tool. You can either use their provided [docker image](infer/docker/1.2.0) to run our examples, or code directly in your browser with [codeboard](https://codeboard.io/projects/11587?view=2.1-21.0-22.0).
To get started with the code in this repository, run the following command with any of the demo c files:
```infer run -- gcc -c demo_theory.c```

## Infer Stages
An Infer run is performed in two phases: capture and analysis. These two phases can be called as separate subcommands:
```infer capture -- javac Test.java```
```infer analyze```

## Theory
Infer utilizes two main concepts ito perform static analysis on code. **Separation Logic** reasons about local operations on memory in chunks, then composes these reasoning chunks together. **Bi-abduction** performs logical inference and analysis on the separation logic pre and post conditions. Navigate to the [Infer documentation](https://fbinfer.com/docs/separation-logic-and-bi-abduction/) on these topics to learn more, or view [demo_theory.c](demo_theory.c) for an example function with separation logic annotations.