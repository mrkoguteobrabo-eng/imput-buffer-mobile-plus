# Input Buffer Mobile+ — cloud-build starter

Target metadata: Geometry Dash Android 2.2081, Geode SDK v5.11.2, Android64.

## What this project currently does
- Defines a minimal Geode mod entry point.
- Includes a standalone C++ timing-queue component.
- Includes a GitHub Actions workflow that attempts an Android64 Geode build
  and uploads the resulting `.geode` as a workflow artifact.

## Important limitations
This is a **starter shell**, not the promised finished click-assist mod.
It currently has no in-game custom menu and does not hook gameplay touch
events, so the queue component is not yet connected to Geometry Dash.
A successful build only means the starter mod can load; it does not mean
the advanced buffer features work.

## Build from a phone using GitHub's website
1. Create a new empty repository in your GitHub account.
2. Upload the contents of this ZIP into the repository (including the
   hidden `.github` folder).
3. Open the repository's Actions tab.
4. Select "Build Input Buffer Mobile+" and tap "Run workflow".
5. If the build succeeds, open that workflow run and download the
   `Input-Buffer-Mobile-Plus-Android64` artifact. It contains the `.geode`.

If the workflow fails, open the failed run and share the error log so the
project can be corrected. Do not rename the source ZIP to `.geode`.

Geode docs: https://github.com/geode-sdk/docs
Build action: https://github.com/geode-sdk/build-geode-mod
