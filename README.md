# CS429HPrep
This is to help you learn, gdb, bash, ssh, and git.
Our goal is to download this repository and run everything in it.

## Setting up SSH

### Windows
You will want Bash on Windows.
Then follow the steps for linux.
[Link to Horid Resource](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/?fbclid=IwAR2ltW-hzfWSqZbuTM7t4oi5NqVB_kPJ3rKvhN674vyIgw6TlgtqoDtU52A)

### Linux
Please replace \<csid\> with you utcs id.
``` bash
  ssh-keygen -t rsa -f ~/.ssh/utlab
  data=`cat ~/.ssh/utlab.pub` && ssh <csid>@atlas-moth.cs.utexas.edu " echo $data >> ~/.ssh/authorized_keys"
  ssh -i ~/.ssh/utlab <csid>@linux.cs.utexas.edu
```

### Mac
This is the same as Linux for SSH.

## Setting up git
On a lab machine, there is no need to do that!!!! YAY.

## Using git
Git is a version control system.
GitHub is an online place to store repositories, which fosters a community of people (That Microsoft might destroy, stay tuned.)
``` bash
  git clone https://github.com/AdityaAtulTewari/CS429HPrep.git
  cd CS429HPrep
```
You have now cloned the directory and should be inside it.

## Setting ourselves us to repeat login
Learning how to write your own scripts will make you a much better programmer.
It will also help you get familiar with bash.

First let us create a directory for our scripts
In your terminal (if on windows in WSL):
``` bash
  mkdir -p ~/scripts
  echo 'export PATH="\$PATH:$HOME/scripts"' >> ~/.bash_profile
```
Whenever you open a new terminal the bash profile is run in order to set up your terminal environment.
So it will now add the scripts directory to our PATH, which will allow us to execute those files.

Make sure to replace \<csid\> with your csid.
``` bash
  echo "#!/bin/bash" > ~/scripts/sshut
  echo "ssh -i ~/.ssh/utlab <csid>@linux.cs.utexas.edu" >> ~/scripts/sshut
  chmod u+x ~/scripts/sshut
  source ~/.bash_profile
```

chmod is a command that allows us to change the execution priveleges of the file, so we can execute the new script we have created.
source is similar to relaoding the terminal, for the particular file specified.

Now just use
``` bash
  sshut
```
To always be able to reliably login from anywhere on this same machine.

## Text Editors
Eventually you will want to edit text on the lab machine.
My personal preference is vim.
On a lab machine we can use vimtutor in order to learn this.
To start the tutor just type.

``` bash
  vimtutor
```

## Knowledge up to Google
In the Information age it is sufficient to know something up to Google Searching (or knowing the right reference) the exact thing we are looking for.
So suddenly knowing what the type of thing we want to do is called is far more important than knowing exactly how to do that thing itself.
Thus definitions become far more important than methods.
This might seem rather obvious, but all of the best Researchers and Software Engineers use Google to efficiently find what they need.
Being able to do that is an invaluable skill that comes through practice.
But often times you will not want to have to look everything up.
So we also want to know things we use every day, so we learn that but just doing it (this is called knowledge by usage).

## Version Control Systems
Version control systems are used in order to ensure we can capture the state of our code and rollback to it.
They have thousands of other features, but this is the main goal.
They are a useful tool that any person who wants a CS degree should have a mastery up to Google.

### Patches
Version control systems keep track of patches in a tree structure in order to have a full history of whatever files you would like.
In this context we view files as a series of patches that are applied one after another to reveal the content of a file.
We can view an individual patch to a file as the insertions and deletions to that file.
Then a patch to the repository is the list of all of the individual file patches to all the files changed between the last state of the repo and the current
one.
To understand patches more in depth, there is some interesting mathematics involved: you can view a simple introduction [here](https://pijul.org/manual/why_pijul.html).
This resource also details why I git is not my favorite version control system.
To be very clear you do not need to understand patch theory, just have an operating knowledge of what I have detailed above.

### Branching
This is what makes version control powerful, it allows for distributed changes to be made in order to ensure that multiple people can edit files at the same time.
Git was one of the first to do this efficiently and well making it the most popular version control software to this date.
But if we make these branches we want to reconcile these changes in a process called merging.
The process to figure this out is hard.
This is essentially the biggest use for branching.
Here is a clean visualization courtesy of Atlassian.
![alt text](https://wac-cdn.atlassian.com/dam/jcr:83323200-3c57-4c29-9b7e-e67e98745427/Branch-1.png?cdnVersion=736)

## What is git
In the above image you may be wondering what a commit is.
It is git's version of a patch.
Git keeps track of changes to binary objects instead of files.
This allows it a way to track things like file name changes, in a clean manner, but also increases the complexity of git's algorithms.
Now that you have cloned this repository (gotten a copy of it on your own computer) we are going to make some changes,

## Git tutorial
There is a file called mult.c in the mult branch.
A checkout is a method to grab some repositories object from somewhere and move it into a working environment.
So let's checkout the mult branch and take a look.
``` bash
  git checkout mult
```
I've made a number of horrible mistakes in the mult.c file.
See if you can find them and use vim to fix them.
After you have fixed that, continue on to the next part.
The next command will do what is called add that file to staging, meaning it will be commited on the next commit.
``` bash
  git add mult.c
  git status
```
The status command will allow us to view the current state of the branch.
``` bash
  git commit -m "Fixed mult"
```
This forms a commit with the message in quotes.
What this does is add a commit to the tree.
This helpful visual describes the staging to commit process courtesy of Microsoft.

![alt text](https://docs.microsoft.com/en-us/azure/devops/repos/git/_img/git_file_status_lifecycle.png?view=azure-devops)
