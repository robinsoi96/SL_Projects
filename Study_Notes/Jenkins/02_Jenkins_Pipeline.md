# Jenkins Pipeline

## Introduction

`Jenkins Pipeline` is a **suite of plugins** which supports implementing and integrating *continuous delivery pipelines* into Jenkins.

Pipeline provides an extensible set of tools for modeling simple-to-complex delivery pipelines "as code" via the **Pipeline domain-specific language (DSL) syntax**.

### Jenkinsfile

The definition of a Jenkins Pipeline is written into a text file (called a `Jenkinsfile`) which can be committed to a project's source control repository. 

This is the foundation of "**Pipeline-as-code**"; treating the CD pipeline as a part of the application to be versioned and reviewed like any other code.

Jenkins Pipeline can also be defined in the Jenkins web UI, but Jenkinsfile is much preferred as the best practice to define the Pipeline.

### Why Pipeline?

Before `Pipeline` is introduced, `Freestyle` is used in Jenkins. 

After Pipeline is introduced, Pipeline is widely used, where you can click on the video link below on "**Freestyle vs Pipeline in Jenkns**" to understand why Pipeline is prefered.

**Video URL:** <a href="https://www.youtube.com/watch?v=IOUm1lw7F58">What Is The Difference Between Freestyle and Pipeline in Jenkins</a>

<br>

## Pipeline Concepts

### Pipeline

A pipeline is a user-defined model of a CD pipeline. 

A Pipeline code `defines your entire build process`, which typically includes **stages**  for building an application, testing it and then delivering it.

`Pipeline` block is a **key part of [Declarative Pipeline syntax](#declarative-pipeline-syntax)**. 

### Node

A node is a `machine which is part of Jenkins environment` and is capable of `executing a Pipeline`.

`Node` block is a **key part of [Scripted Pipeline syntax](#scripted-pipeline-syntax)**.

### Stage

`Stage` block `defines a conceptually distinct subset of tasks performed through the entire Pipeline` (e.g. "Build", "Test" and "Deploy" stages), which is used by many plugins to visualize or present Jenkins Pipeline status/progress.

### Step

`Step` block `defines steps to tell Jenkins what to do` at a particular point in time or "step" in the process.

<br>

## Pipeline Syntax Overview

There are **2 major Pipeline code skeletons**, which are [Declarative Pipeline syntax](#declarative-pipeline-syntax) and [Scripted Pipeline syntax](#scripted-pipeline-syntax).

Take note that both [stage](#stage) and [step](#step) are common elements of both Declarative and Scripted Pipeline syntax.

### Declarative Pipeline Syntax

In Declarative Pipeline syntax, the `pipeline` block defines all the work done throughout your entire Pipeline.

```groovy
// Jenkinsfile (Declarative Pipeline Example)

pipeline {
    agent any // Define agent, here means any available agent
    stages { // Define all stages
        stage('Build') { // 'Build' stage
            steps {
                // Define steps for stage 'Build'
            }
        }
        stage('Test') { // 'Test' stage
            steps {
                // Define steps for stage 'Test'
            }
        }
        stage('Deploy') { // ''Deploy' stage
            steps {
                // Define steps for stage 'Deploy'
            }
        }
    }
}
```

### Scripted Pipeline Syntax

In Scripted Pipeline syntax, one or more `node` blocks do the core work throughout the entire Pipeline.

Although this is not a mandatory requirement of Scripted Pipeline syntax, confining your Pipeline's work inside of a node block does two things:

1. Schedules the steps contained within the block to run by adding an item to the Jenkins queue. As soon as an executor is free on a node, the steps will run.

2. Creates a workspace (a directory specific to that particular Pipeline) where work can be done on files checked out from source control. <br> **Caution**: Depending on your Jenkins configuration, some workspaces may not get automatically cleaned up after a period of inactivity. Refer to the tickets and discussion linked from <a href="https://issues.jenkins.io/browse/JENKINS-2111">JENKINS-2111</a> for more information.

```groovy
// Jenkinsfile (Scripted Pipeline Example)

node { // Execute this Pipeline or any of its stages, on any available agent.
/*

Stage blocks are optional in Scripted Pipeline syntax.

However, implementing stage blocks in a Scripted Pipeline provides clearer visualization of each stage's subset of tasks/steps in the Jenkins UI.

*/
    stage('Build') { // 'Build' stage
        // Define steps for stage 'Build'
    }
    stage('Test') { // 'Test' stage
        // Define steps for stage 'Test'
    }
    stage('Deploy') { // ''Deploy' stage
        // Define steps for stage 'Deploy'
    }
}
```

<br>

## Appendix

- <a href="https://www.jenkins.io/doc/book/pipeline/">Jenkins Pipeline</a>
