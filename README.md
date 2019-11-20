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
  data=`cat ~/.ssh/utlab.pub` && ssh <csid>@linux.cs.utexas.edu " echo $data >> ~/.ssh/authorized_keys"
  ssh -i ~/.ssh/utlab <csid>@linux.css.utexas.edu
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
