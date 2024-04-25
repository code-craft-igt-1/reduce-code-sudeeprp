# Reduce code for a smooth read

Objective of this assignment is to reduce the amount of code that a maintainer has to read.

## What's been done

The image brightener now has two features:
1. Brighten the whole image by adding a constant grayscale value to each pixel
2. Add a brightening image, so we can supply a different grayscale addition for each pixel. E.g., x-ray of the abdomen can be dark in the middle, so we may want to brighten only that part

However, the knowledge of pixel arrangement is not encapsulated in the Image class,
and is also spread in two places within the brightener.

That's why the duplication check fails now.

## Your task - reduce the amount of code

More code means:
- more to read and understand
- more scope for mistakes
- changes to be duplicated in multiple places

**Part 1**: Refactor the code to reduce the amount of code and remove duplication.

**Part 2**: Open the Test Explorer in Visual Studio and run the tests. One test fails due to a bug in `AddBrighteningImage`.
While fixing the bug, also look at ways in which the mistake can be caught at compile time itself.
