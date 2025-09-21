# Dumd drawing editor

You know about Paint the software ? Well it's the same but in worse, you can just just use .dumb files and edit them. You can draw with 4 different colors, erase, and export!!!!! WOOOOW
_Oh and it's also the fdf project from 42, so you can open **.fdf** maps_

## Quick start

Build:

```
make
```

Run:

- Start with a blank image:
  ```
  ./fdf
  ```
- Edit an existing drawing:
  ```
  ./fdf previous_drawing.dumb
  ```
- Open an FDF map:
  ```
  ./fdf map.fdf
  ```

_You can draw on .fdf maps and export them as .dumb._

## Features

- Simple paint-like interface
- Four drawing colors + eraser
- Open and edit .dumb files
- Open .fdf maps (from the 42 project) and draw on them
- Export drawings with automatic versioned filenames

## Controls

- P — Pen mode (draw)
- D — Eraser mode (toggle)
- E — Export the current image (see versioning rules below)

Colors:

- R — Red
- G — Green
- B — Blue
- W — White
- 0 — Black

## Export / Versioning

Press E to export the current image. You can:

- Specify a filename when launching (e.g. `./fdf file.dumb`) — exporting will create a new file with an incremented version, for example `file_V1.dumb`, `file_V2.dumb`, etc.
- If the provided filename already contains a version suffix (e.g. `file_V4.dumb`), the exporter will increase the version number (`file_V5.dumb`).
- If no filename was provided at launch, the program generates a name automatically and adds a version suffix.

## .dumb file format

- First 4 bytes: width (integer)
- Next 4 bytes: height (integer)
- Remaining bytes: pixel data (raw image data)

(Format is binary — keep that in mind when inspecting files.)
