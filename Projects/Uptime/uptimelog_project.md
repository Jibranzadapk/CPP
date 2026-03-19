# UptimeLog Project (Simple Idea)

## Goal
Create a small Linux CLI tool written in C++ that automatically tracks how long a Linux system stays running (uptime) and keeps a history of it.

---

## How It Works

1. A background service starts automatically when Linux boots.
2. The service reads system uptime from `/proc/uptime`.
3. It calculates when the system booted.
4. It saves the session information into a history file.
5. The CLI tool lets the user view and analyze the history.

---

## Two Parts of the Tool

### 1. uptimelogd (Daemon)
- Runs in the background
- Starts automatically when the system boots
- Reads system uptime
- Records uptime sessions

### 2. uptimelog (CLI Tool)
- Shows current uptime
- Shows session history
- Shows statistics
- Allows adding notes

---

## Where Data Is Stored

`~/.local/share/uptimelog/history.json`

Example stored session:

```
{
  "id": 1,
  "boot_time": "2026-03-11T10:00:00",
  "shutdown_time": "2026-03-11T18:00:00",
  "uptime_seconds": 28800,
  "note": ""
}
```

---

## Example CLI Commands

```
uptimelog status
uptimelog history
uptimelog stats
uptimelog note 3 "Power outage"
```

---

## Development Roadmap

```
Phase 1 → read /proc/uptime
Phase 2 → build simple CLI tool
Phase 3 → store uptime history
Phase 4 → create background daemon
Phase 5 → add systemd service
Phase 6 → add stats & notes
```

---

## What You Learn From This Project

- Linux system files (`/proc`)
- C++ CLI programming
- Background services (daemons)
- Structured data storage (JSON)
- Building real Linux utilities

---

## Final Result

A lightweight Linux utility that automatically records system uptime sessions and lets users analyze the reliability and usage of their machine through a simple CLI interface.

