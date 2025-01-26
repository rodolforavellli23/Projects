#!/bin/bash

cat /etc/services
grep -w '80/tcp' /etc/services
grep -w '443/tcp' /etc/services
grep -E -w '22/(tcp|udp)' /etc/services
