<?php
/**
 * @file
 * hosting_scheduled_task2.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hosting_scheduled_task_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-scheduled_task-active'.
  $field_instances['node-scheduled_task-active'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'active',
    'label' => 'Active',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-scheduled_task-arguments'.
  $field_instances['node-scheduled_task-arguments'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'arguments',
    'label' => 'Task Arguments',
    'required' => 0,
    'settings' => array(
      'namespace' => 0,
      'serialization' => 'serialize',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'serialized_field',
      'settings' => array(),
      'type' => 'serialized_hidden',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-scheduled_task-crontab'.
  $field_instances['node-scheduled_task-crontab'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field follows the syntax of cron (with minor differences).
Specifically, each line consists of 5 fields separated by TAB or whitespace:
<pre>MINUTE HOUR DOM MONTH DOW</pre>
<table>
<tbody><tr>
<td>MINUTE</td>
<td>Minutes within the hour (0–59)</td>
</tr>
<tr>
<td>HOUR</td>
<td>The hour of the day (0–23)</td>
</tr>
<tr>
<td>DOM</td>
<td>The day of the month (1–31)</td>
</tr>
<tr>
<td>MONTH</td>
<td>The month (1–12)</td>
</tr>
<tr>
<td>DOW</td>
<td>The day of the week (0–7) where 0 and 7 are Sunday.</td>
</tr>
</tbody></table>
<p>
To specify multiple values for one field, the following operators are
available. In the order of precedence,
</p>
<ul>
<li><code>*</code> specifies all valid values</li>
<li><code>M-N</code> specifies a range of values</li>
<li><code>M-N/X</code> or <code>*/X</code> steps by intervals of X through the specified range or whole valid range</li>
<li><code>A,B,...,Z</code> enumerates multiple values</li>
</ul>
<p>
To allow periodically scheduled tasks to produce even load on the system,
the symbol <code>H</code> (for “hash”) should be used wherever possible.
For example, using <code>0 0 * * *</code> for a dozen daily jobs
will cause a large spike at midnight.
In contrast, using <code>H H * * *</code> would still execute each job once a day,
but not all at the same time, better using limited resources.
</p><p>
The <code>H</code> symbol can be used with a range. For example, <code>H H(0-7) * * *</code>
means some time between 12:00 AM (midnight) to 7:59 AM.
You can also use step intervals with <code>H</code>, with or without ranges.
</p><p>
The <code>H</code> symbol can be thought of as a random value over a range,
but it actually is a hash of the job name, not a random function, so that
the value remains stable for any given project.
</p>
<p>
Beware that for the day of month field, short cycles such as <code>*/3</code> or <code>H/3</code> will not work consistently near the end of most months, due to variable month lengths.
For example, <code>*/3</code> will run on the 1st, 4th, …31st days of a long month, then again the next day of the next month.
Hashes are always chosen in the 1-28 range, so <code>H/3</code> will produce a gap between runs of between 3 and 6 days at the end of a month.
(Longer cycles will also have inconsistent lengths but the effect may be relatively less noticeable.)
</p>
<p>
Empty lines and lines that start with <code>#</code> will be ignored as comments.
</p><p>
In addition, <code>@yearly</code>, <code>@annually</code>, <code>@monthly</code>,
<code>@weekly</code>, <code>@daily</code>, <code>@midnight</code>,
and <code>@hourly</code> are supported as convenient aliases.
These use the hash system for automatic balancing.
For example, <code>@hourly</code> is the same as <code>H * * * *</code> and could mean at any time during the hour.
<code>@midnight</code> actually means some time between 12:00 AM and 2:59 AM.
</p><p>
Examples:
</p>
<pre># every fifteen minutes (perhaps at :07, :22, :37, :52)
H/15 * * * *
# every ten minutes in the first half of every hour (three times, perhaps at :04, :14, :24)
H(0-29)/10 * * * *
# once every two hours every weekday (perhaps at 9:38 AM, 11:38 AM, 1:38 PM, 3:38 PM)
H 9-16/2 * * 1-5
# once a day on the 1st and 15th of every month except December
H H 1,15 1-11 *
</pre>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'crontab',
    'label' => 'Crontab',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-scheduled_task-last_executed'.
  $field_instances['node-scheduled_task-last_executed'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'last_executed',
    'label' => 'Last executed',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_extrawidgets',
      'settings' => array(),
      'type' => 'field_extrawidgets_hidden',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-scheduled_task-next_execution'.
  $field_instances['node-scheduled_task-next_execution'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'next_execution',
    'label' => 'Next execution',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_extrawidgets',
      'settings' => array(),
      'type' => 'field_extrawidgets_hidden',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-scheduled_task-one_time'.
  $field_instances['node-scheduled_task-one_time'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'one_time',
    'label' => 'One-time',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-scheduled_task-task_target'.
  $field_instances['node-scheduled_task-task_target'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => 'Select the target of the task.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'task_target',
    'label' => 'Task Target',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'disable',
          'action_on_edit' => 1,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => FALSE,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-scheduled_task-task_type'.
  $field_instances['node-scheduled_task-task_type'] = array(
    'bundle' => 'scheduled_task',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'task_type',
    'label' => 'Task type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Active');
  t('Crontab');
  t('Last executed');
  t('Next execution');
  t('One-time');
  t('Select the target of the task.');
  t('Task Arguments');
  t('Task Target');
  t('Task type');
  t('This field follows the syntax of cron (with minor differences).
Specifically, each line consists of 5 fields separated by TAB or whitespace:
<pre>MINUTE HOUR DOM MONTH DOW</pre>
<table>
<tbody><tr>
<td>MINUTE</td>
<td>Minutes within the hour (0–59)</td>
</tr>
<tr>
<td>HOUR</td>
<td>The hour of the day (0–23)</td>
</tr>
<tr>
<td>DOM</td>
<td>The day of the month (1–31)</td>
</tr>
<tr>
<td>MONTH</td>
<td>The month (1–12)</td>
</tr>
<tr>
<td>DOW</td>
<td>The day of the week (0–7) where 0 and 7 are Sunday.</td>
</tr>
</tbody></table>
<p>
To specify multiple values for one field, the following operators are
available. In the order of precedence,
</p>
<ul>
<li><code>*</code> specifies all valid values</li>
<li><code>M-N</code> specifies a range of values</li>
<li><code>M-N/X</code> or <code>*/X</code> steps by intervals of X through the specified range or whole valid range</li>
<li><code>A,B,...,Z</code> enumerates multiple values</li>
</ul>
<p>
To allow periodically scheduled tasks to produce even load on the system,
the symbol <code>H</code> (for “hash”) should be used wherever possible.
For example, using <code>0 0 * * *</code> for a dozen daily jobs
will cause a large spike at midnight.
In contrast, using <code>H H * * *</code> would still execute each job once a day,
but not all at the same time, better using limited resources.
</p><p>
The <code>H</code> symbol can be used with a range. For example, <code>H H(0-7) * * *</code>
means some time between 12:00 AM (midnight) to 7:59 AM.
You can also use step intervals with <code>H</code>, with or without ranges.
</p><p>
The <code>H</code> symbol can be thought of as a random value over a range,
but it actually is a hash of the job name, not a random function, so that
the value remains stable for any given project.
</p>
<p>
Beware that for the day of month field, short cycles such as <code>*/3</code> or <code>H/3</code> will not work consistently near the end of most months, due to variable month lengths.
For example, <code>*/3</code> will run on the 1st, 4th, …31st days of a long month, then again the next day of the next month.
Hashes are always chosen in the 1-28 range, so <code>H/3</code> will produce a gap between runs of between 3 and 6 days at the end of a month.
(Longer cycles will also have inconsistent lengths but the effect may be relatively less noticeable.)
</p>
<p>
Empty lines and lines that start with <code>#</code> will be ignored as comments.
</p><p>
In addition, <code>@yearly</code>, <code>@annually</code>, <code>@monthly</code>,
<code>@weekly</code>, <code>@daily</code>, <code>@midnight</code>,
and <code>@hourly</code> are supported as convenient aliases.
These use the hash system for automatic balancing.
For example, <code>@hourly</code> is the same as <code>H * * * *</code> and could mean at any time during the hour.
<code>@midnight</code> actually means some time between 12:00 AM and 2:59 AM.
</p><p>
Examples:
</p>
<pre># every fifteen minutes (perhaps at :07, :22, :37, :52)
H/15 * * * *
# every ten minutes in the first half of every hour (three times, perhaps at :04, :14, :24)
H(0-29)/10 * * * *
# once every two hours every weekday (perhaps at 9:38 AM, 11:38 AM, 1:38 PM, 3:38 PM)
H 9-16/2 * * 1-5
# once a day on the 1st and 15th of every month except December
H H 1,15 1-11 *
</pre>');

  return $field_instances;
}
