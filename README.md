# CS429HPrep
This is to help you learn, gdb, bash, ssh, and git.
Our goal is to download this repository and run everything in it.

## Setting up SSH

### Windows
You will want Bash on Windows.
Then follow the steps for Linux.
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

chmod is a command that allows us to change the execution privileges of the file, so we can execute the new script we have created.
source is similar to reloading the terminal, for the particular file specified.

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
The next command will do what is called add that file to staging, meaning it will be committed on the next commit.
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

Test the code by running the below command, if it fails be sure to keep making edits until you succeed.
``` bash
  make mult
  ./mult
```
Once you are finished make sure to commit that file to the mult branch.
### Git Checkout
Then we are going to discuss several different ways of moving the changes over to the master branch.
In order to do this we first want to be on the master branch.
This command should move you to the master branch:
``` bash
  git checkout master
```
To show you the different ways of doing this we will also explore ways to undo changes as well.
These are techniques that you always, always look up the exact command before you execute.
They are dangerous and you want to make sure you execute exactly what you want.

The first method is checking out the file.
It is a simple way of moving one file over.
This is recommend for very small changes, as it does not create an actual commit and gives you flexibility to throw changes away.
``` bash
  git checkout mult -- mult.c
```
The more general version of this command is:
``` bash
  git checkout <branch> -- <paths>
```
Omitting the paths has the side effect of switching branches.
Now it is just like you have edited the mult.c file to change it to what you want manually and you can commit it to the master branch like before.
This method however does not track where the changes have come from.
In order to undo this change before you have committed it do:
``` bash
  git checkout mult.c
```
If you already committed this change then we want to delete the last commit.
``` bash
  git reset --hard HEAD~1
```
Again do not use that command unless you are absolutely sure you typed it correctly.
Small changes can do sad things.
Reset commands in general set the state of your branch to some previous state and thus should be well researched before use.

### Git Merge
For larger changes where we would like to combine the HEAD (the topmost commit) of two branches, we use a merge commit.
They can be formulated in various ways.
The best practice is to merge to the target branch" into the "working branch" and then merge the new "working branch" into the target branch.
This allows you to incorporate changes that have been made to the target without disturbing changes other people could be making.
This method also has the benefit of creating essentially a copy of the intended on the "working branch".
Which can be further modified and then later re-merged to the target seamlessly.
Merging has so many options and can become complicated very quickly if we loose sight of the basic tree structure of a repository.
Let us remind ourselves of the earlier diagram:

![alt text](https://wac-cdn.atlassian.com/dam/jcr:83323200-3c57-4c29-9b7e-e67e98745427/Branch-1.png?cdnVersion=736)

In our example the common branch is master and the feature branch is mult.
The above diagram is about what we want at the end result.
But we will also create a merge commit on the mult branch.
So checkout the mult branch.
Then run the following.
``` bash
  git merge master
```
In some circumstances you will have a merge conflict, [here](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/resolving-a-merge-conflict-using-the-command-line) is a good resource for managing those.
You should not have one here.
Now we want to view this commit by running:
``` bash
  git log
```
You should see some auto generated commit that specifies this is a merge commit.
Whenever you want to quit just type the letter `q`.
Reading through the git log is a very important skill, [this resource](https://git-scm.com/book/en/v2/Git-Basics-Viewing-the-Commit-History) should help.
Before we continue, ensure everything is in proper working order, and
Now if we want to move that commit to the master branch, checkout the master branch and run.
``` bash
  git merge mult
```
Notice this is the mirror of the above merge command, because we are merging the "working branch" into the "target branch" now.
So make sure that everything works and we can continue to the most interesting method to fix the changes.
Obviously we should on both branches delete the commit with the reset command.
Make sure you check the git log before running the command.
This time however use the git log to find the last commit you want to reset to.
``` bash
  git reset --hard <commit-id>
```
Also to check the branch you are on run:
``` bash
  git branch
```
Thus it is reasonable to understand that HEAD~1 must represent some commit id, this commit id is the one before the current HEAD commit id.
The obvious question here of course is: What is a commit id?
It is a unique representation of the commit in that place as a number.

### Git Cherry-Pick
The true power of patches is I can apply them in any order I want if I am sufficiently motivated (bored).
This allows me to recognize parts of things that I would like transfered from branch to branch.
In order to use this tool effectively one must have at least one commit per major repository change.
That metric can be expounded upon by your own exploration.
But to continue we want to apply the set of commits writing and fixing the mult.c file.
In this case, a merge is most useful, so I have created another two branches for practicing this technique.
One called `pow` and the other called `weirdstuff`.
When on the `pow` branch you should see at the top of the file the imports are missing.
They are included in some commit in the `weirdstuff` branch.
Make sure to use:
``` bash
  git log -p
```
When viewing the log for `weirdstuff` in order to see the content of the commits.
We want to cherry-pick this commit onto the master branch.
We can do this by switching to the `pow` branch and running:
``` bash
  git cherry-pick <commit-id>
```
This will try and merge the changes from that commit in weirdstuff to pow.
Make sure that you deal with the merge conflict.
Then follow the directions in the `git status` command.
