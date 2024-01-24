#!/usr/bin/env bash

# etc
mkdir /etc/authntf
cp build/authntf.conf /etc/authntf/authntf.conf

# bin
cp build/authntf /usr/bin/authntf

# system service
cp build/authntf.service /usr/lib/systemd/system/authntf.service

echo "Auth notifier service installed successfully"