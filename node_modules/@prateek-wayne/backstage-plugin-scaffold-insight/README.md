# scaffold-insight

Welcome to the scaffold-insight plugin! 🚀

_This plugin was created through the Backstage CLI_

## Installation

To install the plugin in your Backstage app, follow these steps:

1. From your Backstage root directory, run:
    ```sh
    yarn --cwd packages/app add @prateek-wayne/backstage-plugin-scaffold-insight
    ```

2. In `App.tsx`, add the following import:
    ```tsx
    import { ScaffolderAnalyticsPage } from '@prateek-wayne/backstage-plugin-scaffold-insight';
    ```

3. Add the route to the `App.tsx`:
    ```tsx
    <Route path="/scaffold-insight" element={<ScaffolderAnalyticsPage />} />
    ```

4. Add to the sidebar item routing to the new page `Root.tsx`:
    ```tsx
    // In packages/app/src/components/Root/Root.tsx
    import TimelineIcon from '@material-ui/icons/Timeline';

    {
        /* other sidebar items... */
    }

    <SidebarItem icon={TimelineIcon} to="scaffold-insight" text="Insights" />

    ```

## Setup the scaffolder.yaml

To add data about the template, update your `scaffolder.yaml` file. Here is an example:

```yaml
apiVersion: scaffolder.backstage.io/v1beta3
kind: Template
metadata:
  name: JavaWorkflowIntegration
  title: Java Workflow Integration
  description: A template to seamlessly integrate Java workflows, enhancing development efficiency and consistency.
  efficiency-boost:
    value: 45
    unit: minutes
    impact: 'Streamlines Java development processes for better productivity'
```

The efficiency-boost section is extra metadata that this plugin will read from the template file.

Screenshot 📸
<img width="1668" alt="image" src="https://github.com/user-attachments/assets/cd69303c-75fb-411a-9f37-319cfc493e6a">
Contributions
This plugin can be improved a lot. Please feel free to raise issues and features. 💡