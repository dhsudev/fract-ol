#!/bin/sh

git --git-dir=.githome filter-branch --env-filter '

OLD_EMAIL="ltrevin-@studdent.42barcelona.com"
CORRECT_NAME="dhsudev"
CORRECT_EMAIL="lua@gnomo.net"

if [ "$GIT_COMMITTER_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
if [ "$GIT_AUTHOR_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags

