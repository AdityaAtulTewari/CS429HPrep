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
