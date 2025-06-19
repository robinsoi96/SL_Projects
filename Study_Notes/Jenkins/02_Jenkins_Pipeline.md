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

## Appendix

- <a href="https://www.jenkins.io/doc/book/pipeline/">Jenkins Pipeline</a>
