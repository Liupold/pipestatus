# Simple status line generator. (pipestatus)


# - The Problem
While using minimal status bar like (`dwm`'s bar , `lemonbar`). They generally display a text passed to them. (Very minimal by design). But generating that is a *pain in the behind*. Specially if they must dynamically update like `volume`, `brightness` etc, one way to do so is by writting a very big `while loop` (or dividing it into scripts), This create additional dynamic updates which is for all intense and purposes is not very effective. Moreover when the bar updates (generally) every value is also updated, which is a bloat.

   - ### what if i use a way to subscribe to a change?
        well yes that's a solution but manging a lot of loops and hooks can be intemidating. Can there be a better way?

# - The Solution

This solution is based on a `named pipes`.

We start our status bar by defining a template.

```bash
pipestatus -t "Value of Key1: <KEY1>, value of Key2: <KEY2>" -f /tmp/pipestatus.pipe | lemonbar
```
we want `<KEY1>` and `<KEY2>` in our bar to be replaced by some text, say `value1` `value2` respectively.

This can be achieved by a simple `echo` (or writing to file in any way you want)
```
echo "KEY1:value1" > /tmp/pipestatus.pipe; echo "KEY2:value2" > /tmp/pipestatus.pipe
```

or

```
printf "KEY1:value1\nKEY2:value2\n" > /tmp/pipestatus.pipe
```

* Each update is separate from one another.
* The values are stored and can be dynamically and separately updated.
* The template and the updates are handled separately.
* KEYS can be anything you want, no need to be uppercase. (I used uppercase to differentiate)

## Build instruction

```sh
./build.sh
```
* And copy the binary to path.

## Why use pipestatus

* Fast and efficient (C++)

## Modules
There are a few modules here for some basic stuff which are very efficient. They are not documented yet. (Sorry), But they are simple enough for u guys.

## RECOMMENDATION

A sample implimentation of using this in `dwm's bar` can be found in the `Example`dir.
To run a exmple you need to have `Font Awesome` and `Fira Code` Fonts.

```bash
./Example/launch-bar-dwm
```

mail:rohnch@protonmail.ch
