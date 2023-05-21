#!/bin/bash

# Assign variables
MYDIR="$HOME/MYDIR"
USERNAME=$(whoami)
FILENAME="$USERNAME"
NEWFILE="$HOME/NEWFILE"
MYDIRCOPY="$HOME/MYDIRCOPY"
DOTDOT="$HOME/DOTDOT"
LYRICS="$HOME/C\:/WINDOWS/my baby's love - lyrics.txt"

# Create MYDIR and set its permissions
mkdir -p "$MYDIR"
chmod 770 "$MYDIR"
chmod +t "$MYDIR"

# Create and populate NEWFILE
touch "$NEWFILE"

# Create a hardlink
ln "$NEWFILE" "$MYDIR/$FILENAME"

# Make a copy of MYDIR
cp -rp "$MYDIR" "$MYDIRCOPY"

# Put lines in NEWFILE based on UID
UID_LAST_DIGIT=$(($(id -u) % 10))
for ((i=1; i<=UID_LAST_DIGIT; i++))
do
    echo "Line $i" >> "$NEWFILE"
done

# Copy files from /etc/ to DOTDOT
mkdir -p "$DOTDOT"
find /etc/ -name "*\**\**" -type f -exec cp {} "$DOTDOT" \;

# Display the number of users using bash as default shell
grep -c "/bin/bash" /etc/passwd

# Create symlink for lyrics
mkdir -p "$HOME/C\:/WINDOWS/"
ln -s /bin/ "$LYRICS"

# Check for a file with a four-letter word
FOUND=$(find "$HOME" -type f -iname "*f?k*")
if [[ ! -z "$FOUND" ]]
then
    echo "Warning: A file with a four-letter word beginning with f and ending with k was found."
fi
