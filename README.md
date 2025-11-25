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

## Workflows
**Global Workflow**
```infer run -- gcc -c demo_theory.c```

**Differential Workflow**
```infer run --reactive -- gcc -c demo_theory.c```

**Differential Workflow - Combined Changes**
```infer run --continue -- gcc -c demo_theory.c```

## Annotations and Thread Safety
Infer can also utilize custom Java annotations to detect errors. Infer's annotations are compile-time markers that help the static analyzers understand how a class is supposed to behave.

They don't change runtime behavior, are not enforceable, and are not involved in any code generation. They simply allow the test engineer to manually provide signals to Infer's analysis engine.

These annotations can be found at:
```import com.facebook.infer.annotation.*;```

One example of this is the @ThreadSafe annotation in the [demo_datarace.java](demo_datarace.java) example file. This contains a simple Java class that sets an integer member variable. When the @ThreadSafe annotation is present, Infer understands that this class should be safe to access concurrently, but is not. Adding the synchronized keyword resolves the THREAD_SAFETY_VIOLATION error correctly raised by Infer.

Additionally, you can customize what checkers are utilized in an Infer run. For example, [RacerD](https://fbinfer.com/docs/checker-racerd) performs thread safety analysis, and can be enabled/disabled depending on your troubleshooting preferences:

To enable racerD...
```infer --racerd -- javac -cp lib/infer-annotation-0.18.0.jar -d build demo_datarace.java```

To disable racerD...
```infer --no-racerd -- javac -cp lib/infer-annotation-0.18.0.jar -d build demo_datarace.java```

To only run racerD...
```infer --racerd-only -- javac -cp lib/infer-annotation-0.18.0.jar -d build demo_datarace.java```